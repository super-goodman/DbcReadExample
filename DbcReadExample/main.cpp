#include <QtCore/QCoreApplication>
#include <QFile>
#include <windows.h>

using namespace std;

struct DbcHeader
{
	UINT32 wdbc;
	UINT32 rows;
	UINT32 cols;
	UINT32 rlen;
	UINT32 tlen;
};
char* stringData = nullptr;

inline QDataStream& operator>>(QDataStream& out, DbcHeader& DbcHeader)
{
	out >> DbcHeader.wdbc >> DbcHeader.rows >> DbcHeader.cols >> DbcHeader.rlen >> DbcHeader.tlen;
	return out;
}

//读取int32 column
UINT getUint32(char* data, int field)
{
	int index = field * 4;
	return *(UINT*)(data + index);
}

//读取String block 
QString getString(char* data, int field)
{
	int offset = getUint32(data, field);
	int i = 0;
	char str[1024] = {};

	while ((str[i] = stringData[offset++]) != 0)
		i++;

	return QString::fromLatin1(str);
}

int main(int argc, char const* argv[])
{
	//读取Dbc
	QFile file("Spell.dbc");
	if (!file.open(QIODevice::ReadOnly))
		return false;


	//设置二进制流
	QDataStream out(&file);
	out.setByteOrder(QDataStream::LittleEndian);


	//读取header块
	DbcHeader header;
	out >> header;
	
	//读取字符区域
	file.seek(file.size() - header.tlen);
	stringData = new char[header.tlen];
	out.readRawData(stringData, header.tlen);
	//重置数据流到header后
	file.seek(sizeof(header));

	//读取技能信息
	for (size_t i = 0; i < header.rows; i++)
	{
		//读取内容
		char* rowdata = new char[header.rlen];
		out.readRawData(rowdata, header.rlen);
		UINT id = getUint32(rowdata,0);
		QString name = getString(rowdata,136);
		qDebug() << id<<name;

		delete[] rowdata;
	}

	file.close();
	delete[] stringData;
	return 0;
}