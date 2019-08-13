//���ݿ�����йصĻ���
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
//֧��sql server��ص���
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

//֧��Oracle
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
			dbFactory->CreateDBConnection(); //����������
		connection->ConnectionString("...");

		IDBCommand * command = dbFactory->CreateDBCommand(); //����������
		command->CommandText("...");
		command->SetConnection(connection);

		IDBDataReader * reader = command->ExecuteReader();
		while (reader->Read()) {
		
		}
	}
};