// expcc.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

#include <queue>
#include <map>
#include <forward_list>
#include <list>

template <typename T>
class lrucc {
public:
	lrucc(size_t capacity) :
		capacity(capacity){

	}

	void insert(const std::string &key, const T &value) {
		while(size() >= capacity)
			remove_lru();
		
		storage[key] = value;

		order.push_back(key);
	}
	T &get(const std::string &key) {
		order.remove(key);
		order.push_back(key);

		return storage[key];
	}

	void clear() {
		order.clear();
		storage.clear();
	}

	size_t size() {
		return storage.size();
	}

private:
	void remove_lru() {
		auto &key = order.front();
		storage.erase(storage.find(key));
		order.pop_front();
	}

private:
	int capacity;
	std::map<std::string, T> storage;
	std::list<std::string> order;
};

template <typename T, typename REFRESH_INTERVAL, typename REFRESH_FUNC>
class expcc {
public:

	struct slot {
		unsigned int last_access;
		T data;
	};

private:
public:
	
};

int main()
{
	lrucc<int> lru(2);


	lru.insert("A", 2);
	lru.insert("B", 3);
	lru.insert("C", 3);
	lru.insert("D", 3);

    return 0;
}

