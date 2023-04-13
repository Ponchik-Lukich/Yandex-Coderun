#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <set>

using namespace std;

class DataCenter {
public:
    int id{};
    long long product{};
    DataCenter() = default;
    DataCenter(int id, long long product) : id(id), product(product) {}

    bool operator<(const DataCenter& other) const {
        if (product != other.product) {
            return product < other.product;
        }
        return id > other.id;
    }
};

class DataCenterMin: public DataCenter {
public:
    DataCenterMin() = default;
    DataCenterMin(int id, long long product) : DataCenter(id, product) {}

    bool operator<(const DataCenter& other) const {
        if (product != other.product) {
            return product < other.product;
        }
        return id < other.id;
    }
};

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<set<int>> disabled_servers(n);
    vector<long long> open_calls(n, 0);
    vector<int> enabled_servers(n, m);
    vector<DataCenterMin> products(n);
    set<DataCenterMin> bst;
    set<DataCenter> bstMax;

    for (int i = 0; i < n; ++i) {
        products[i] = DataCenterMin(i, 0);
        bst.insert(products[i]);
        bstMax.insert(products[i]);
    }

    for (int i = 0; i < q + 1; ++i) {
        string line, command;
        getline(cin, line);
        stringstream ss(line);
        ss >> command;
        int datacenter, server;

        if (command == "DISABLE") {
            ss >> datacenter >> server;
            datacenter--;
            server--;
            if (disabled_servers[datacenter].insert(server).second) {
                enabled_servers[datacenter]--;
            }

            bst.erase(products[datacenter]);
            bstMax.erase(products[datacenter]);
            products[datacenter].product = enabled_servers[datacenter] * open_calls[datacenter];
            bst.insert(products[datacenter]);
            bstMax.insert(products[datacenter]);

        } else if (command == "RESET") {
            ss >> datacenter;
            datacenter--;

            bst.erase(products[datacenter]);
            bstMax.erase(products[datacenter]);
            disabled_servers[datacenter].clear();
            enabled_servers[datacenter] = m;
            open_calls[datacenter]++;
            products[datacenter].product = m * open_calls[datacenter];
            bst.insert(products[datacenter]);
            bstMax.insert(products[datacenter]);

        } else if (command == "GETMAX") {
            auto max_iter = prev(bstMax.end());
            cout << max_iter->id + 1 << endl;

        } else if (command == "GETMIN") {
            auto min_iter = bst.begin();
            cout << min_iter->id + 1 << endl;
        }
    }
    return 0;
}