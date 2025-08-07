#include <iostream>
#include <map>
#include <string>
#include <unordered_map>

class SimpleBigTable {
   public:
    // RowKey -> (Column -> Value)
    using ColumnMap = std::unordered_map<std::string, std::string>;
    std::map<std::string, ColumnMap> table;  // 有序 map 便于前缀扫描

    // 插入数据
    void Put(const std::string& rowKey,
             const std::string& column,
             const std::string& value) {
        table[rowKey][column] = value;
    }

    // 获取数据
    bool Get(const std::string& rowKey,
             const std::string& column,
             std::string& out) {
        auto rowIt = table.find(rowKey);
        if (rowIt == table.end())
            return false;
        auto colIt = rowIt->second.find(column);
        if (colIt == rowIt->second.end())
            return false;
        out = colIt->second;
        return true;
    }

    // 删除整行或某列
    void Delete(const std::string& rowKey, const std::string& column = "") {
        auto it = table.find(rowKey);
        if (it == table.end())
            return;

        if (column.empty()) {
            table.erase(it);
        } else {
            it->second.erase(column);
            if (it->second.empty()) {
                table.erase(it);
            }
        }
    }

    // 扫描 row key 前缀
    void Scan(const std::string& rowPrefix) {
        for (auto& [rowKey, columns] : table) {
            if (rowKey.rfind(rowPrefix, 0) == 0) {  // 判断是否以 rowPrefix 开头
                std::cout << "RowKey: " << rowKey << "\n";
                for (auto& [col, val] : columns) {
                    std::cout << "  " << col << " = " << val << "\n";
                }
            }
        }
    }
};

int main() {
    SimpleBigTable bt;

    // 插入数据
    bt.Put("user:1001", "info:name", "Alice");
    bt.Put("user:1001", "info:age", "24");
    bt.Put("user:1002", "info:name", "Bob");
    bt.Put("user:1002", "info:age", "28");

    // 获取数据
    std::string val;
    if (bt.Get("user:1001", "info:name", val)) {
        std::cout << "user:1001 name = " << val << "\n";
    }

    // 扫描前缀为 user:
    std::cout << "\nScan user:\n";
    bt.Scan("user:");

    // 删除某列
    bt.Delete("user:1001", "info:age");

    // 删除整行
    bt.Delete("user:1002");

    std::cout << "\nAfter delete:\n";
    bt.Scan("user:");

    return 0;
}
