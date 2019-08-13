//数据库访问有关的基类
class IDBConnection {

};

class IDBCommand {

};

class IDataReader {

};

class IDBFactory {
public:
	virtual IDBConnection * CreateDBConnection() = 0;
	virtual IDBCommand * CreateDBCommand() = 0;
	virtual IDataReader * CreateDataReader() = 0;
};
//支持sql server相关的类
class SqlDBFactory : public  IDBFactory {
	virtual IDBConnection * CreateDBConnection() {
		return new SqlConnection();
	}
	virtual IDBCommand * CreateDBCommand() {
		return new SqlCommand();
	}
	virtual IDataReader * CreateDataReader() {
		return new SqlDataReader();
	}
};

class SqlConnection : public IDBConnection {

};


class SqlCommand : public IDBCommand {

};


class SqlDataReader : public IDataReader {

};

//支持Oracle
class OracleConnection : public IDBConnection {

};

class OracleCommand : public IDBCommand {

};

class OracleDateaReader : public IDataReader {

};


class EmployeeDAO {
	IDBFactory * dbFactory;

public:
	vector<EmployeeDAO> GetEmployees() {
		IDBConnection * connection =
			dbFactory->CreateDBConnection(); //依赖抽象类
		connection->ConnectionString("...");

		IDBCommand * command = dbFactory->CreateDBCommand(); //依赖抽象类
		command->CommandText("...");
		command->SetConnection(connection);

		IDBDataReader * reader = command->ExecuteReader();
		while (reader->Read()) {
		
		}
	}
};