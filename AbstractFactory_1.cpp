class EmployeeDAO {
public:
	vector<EmployeeDAO> GetEmployees() {
		SqlConnection * connection =
			new SqlConnection(); //依赖具体类
		connection->ConnectionString = "...";

		SqlCommand * command = new SqlCommand(); //依赖具体类
		command->CommandText = "...";
		command->SetConnection(connection);

		SqlDataReader * reader = command->ExecuteReader();
		while (reader->Read()) {

		}
	}
};