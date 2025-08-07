#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>

class WAL {
   public:
    WAL(const std::string& logFile) : log_file(logFile) {}

    void write_log(const std::string& key, const std::string& value) {
        std::ofstream ofs(log_file, std::ios::app);
        ofs << "SET " << key << " " << value << std::endl;
        ofs.close();
    }

    void recover(std::unordered_map<std::string, std::string>& db) {
        std::ifstream ifs(log_file);
        std::string command, key, value;
        while (ifs >> command >> key >> value) {
            if (command == "SET") {
                db[key] = value;
            }
        }
        ifs.close();
    }

    void clear_log() {
        std::ofstream ofs(log_file, std::ios::trunc);  // 清空日志
        ofs.close();
    }

   private:
    std::string log_file;
};

// 模拟数据库操作
class SimpleDB {
   public:
    SimpleDB(const std::string& logFile) : wal(logFile) {
        wal.recover(storage);
    }

    void set(const std::string& key, const std::string& value) {
        wal.write_log(key, value);  // 预写日志
        storage[key] = value;       // 实际写数据
    }

    std::string get(const std::string& key) { return storage[key]; }

    void commit() {
        wal.clear_log();  // 模拟提交后清空日志（可改为 checkpoint）
    }

   private:
    std::unordered_map<std::string, std::string> storage;
    WAL wal;
};

int main() {
    SimpleDB db("wal.log");

    // db.set("user", "Alice");
    // db.set("score", "95");

    std::cout << "User: " << db.get("user") << std::endl;
    std::cout << "Score: " << db.get("score") << std::endl;

    db.commit();  // 模拟事务提交
    return 0;
}
