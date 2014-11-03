-----------------

	// 创建对象
	INIConfig * conf = INIConfig(profile);

	// 读取文件 （返回值决定是否成功)
	bool ReadINI();

	// 写入文件 （返回值决定是否成功)
	bool WriteINI();

	// 加入新节点
	bool AddString(string, string);

	// 加入新节点（例）
	bool AddString("users.name", "nljb");

	// 写入配置,新建,修改
	bool PutString(string, string);

	// 写入配置,新建,修改（例）
	bool PutString("users.name, "nljb");

	// 读取字符串值
	string GetString(string, string);

	// 读取字符串值（例）
	string GetString("users.name", "nljb");

	// 读取数字值
	int GetInt(string, int);

	// 读取数字值（例）
	int GetInt("users.size", 100);

	// 读取节点所有KEY值
	vector<string> GetChildString(string);

	// 读取节点所有KEY值（例）
	vector<string> GetChildString("users");
