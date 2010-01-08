/*
 * Driver for cprog06lab1a. Written 2006-08-27 by Gunnar Kreitz <gkreitz>
 *
 * If you need to modify this file to solve the assignment, you're most likely
 * solving it the wrong way.
 */

#include "vector.h"
#include <vector>
#include <string>
#include <iostream>
#include <cassert>
#include <stdexcept>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::size_t;

namespace { // Anonymous namespace

	template<typename T>
	class VectorTester {
		public:
			void handle() {
				string command;
                int row = 1;
				while(cin >> command) {
                    row++;
					if(command == "new" ) {
						const size_t size = read_size_or_die();
						vectors.push_back(new Vector<T>(size));
                        cout << "L" << row << ":V" << vectors.size() << "; new" << std::endl;
					} else if(command == "newcopy") {
						size_t idx = read_idx_or_die();
						vectors.push_back(new Vector<T>(* const_cast<const Vector<T>*>(vectors[idx])));
                        cout << "L" << row << ":V" << vectors.size() << "; new(" << idx << ")" << std::endl;
					} else if(command == "delete") {
						const size_t idx = read_idx_or_die();
						delete vectors[idx];
						vectors[idx] = 0;
                        cout << "L" << row << ":V" << idx << "; del" << std::endl;
					} else if(command == "is_empty") {
						const size_t idx = read_idx_or_die();
						try {
							bool is_empty = (*const_cast<const Vector<T>*>(vectors[idx])).is_empty();
							if (is_empty) cout << "L" << row << ":V" <<  idx << "; is empty" << std::endl;
							else cout << "L" << row << ":V" << idx << "; has " << vectors[idx]->size() << " items " << std::endl;
						} catch (std::out_of_range oor) {
							cout << "L" << row << ":V" << idx << "; OOR in is_empty" << std::endl;
						}
					} else if(command == "copy") {
						const size_t from = read_idx_or_die();
						const size_t to = read_idx_or_die();
						*vectors[to] = *const_cast<const Vector<T>*>(vectors[from]);
                        cout << "L" << row << ":V" << from << "->" << to << std::endl;
					} else if(command == "set") {
						const size_t idx = read_idx_or_die();
						const size_t idx2 = read_size_or_die();
						T value;
						cin >> value;
						try {
							(*vectors[idx])[idx2] = value;
						} catch (std::out_of_range oor) {
							cout << "L" << row << ":V" << idx << "; OOR in set" << std::endl;
						}
					} else if(command == "print") {
						const size_t idx = read_idx_or_die();
                        cout << "L" << row << ":V" << idx << "; ";
						for(size_t i = 0; i < vectors[idx]->size(); ++i) {
							if(i)
								cout << " ";
							cout << (*vectors[idx])[i];
						}
						cout << std::endl;
					} else if(command == "get") {
						const size_t idx = read_idx_or_die();
						const size_t idx2 = read_size_or_die();
                        cout << "L" << row << ":V" << idx << "[" << idx2 << "]=";
						try {
							cout << (*const_cast<const Vector<T>*>(vectors[idx]))[idx2] << std::endl;
						} catch (std::out_of_range oor) {
							cout << "OOR in get" << std::endl;
						}
					} else if(command == "push_back") {
						const size_t idx = read_idx_or_die();
						T value;
						cin >> value;
						vectors[idx]->push_back(static_cast<const T>(value));
					} else if(command == "insert") {
						const size_t idx = read_idx_or_die();
						const size_t idx2 = read_size_or_die();
						T value;
						cin >> value;
						try {
							vectors[idx]->insert(static_cast<const size_t>(idx2), static_cast<const T>(value));
						} catch (std::out_of_range oor) {
							cout << "L" << row << ":V" << idx << "; OOR in insert" << std::endl;
						}
					} else if(command == "erase") {
						const size_t idx = read_idx_or_die();
						const size_t idx2 = read_size_or_die();
						try {
							vectors[idx]->erase(idx2);
						} catch (std::out_of_range oor) {
							cout << "L" << row << ":V" << idx << "; OOR in erase" << std::endl;
						}
					} else if(command == "clear") {
						const size_t idx = read_idx_or_die();
						vectors[idx]->clear();
					} else if(command == "size") {
						const size_t idx = read_idx_or_die();
						cout << "L" << row << ":V" << idx << "; " << const_cast<const Vector<T> *>(vectors[idx])->size() << endl;
					} else if(command == "sort") {
						const size_t idx = read_idx_or_die();
						bool ascending;
						cin >> ascending;
						vectors[idx]->sort(static_cast<const bool>(ascending));
					} else {
						assert(!"Unknown command");
					}
				}
			}

		private:
			/*
			 * There is no way in standard C++ to read a size_t. The way we solve it here is to
			 * read it as an unsigned long. This program will not be used with too large inputs.
			 * Another way would be to use size_t ret; scanf("%zu", &ret); which is legal in C99
			 * and thus most likely will be OK in C++0x. It's already supported by most compilers.
			 * If it was changed to using scanf instead, the sync_with_stdio(false)
			 * would need to be removed.
			 */
			size_t read_size_or_die() {
				unsigned long ret;
				cin >> ret;
				assert(cin);
				return static_cast<size_t>(ret);
			}

			size_t read_idx_or_die() {
				size_t ret = read_size_or_die();
				assert(ret < vectors.size() && vectors[ret]);
				return ret;
			}

			std::vector<Vector<T> *> vectors;
	};

	/*
	 * A non-PoD-class to ensure that people do not attempt to move objects around the wrong way.
	 */
	class Problematic {
		public:
			explicit Problematic(const int data = 0) : myself(this), data(data) { }
			Problematic(const Problematic &rhs) : myself(this), data(rhs.data) { }
			const Problematic &operator=(const Problematic &rhs) {
				assert(myself == this);
				data = rhs.data;
				return *myself;
			}
			~Problematic() {
				assert(myself == this);
			}
			int get_data() const {
				assert(myself == this);
				return myself->data;
			}
			bool operator<(const Problematic &rhs) const {
				assert(myself == this);
				return (data & 0xF) < (rhs.data & 0xF);
			}

		private:
			friend std::istream &operator>>(std::istream &is, Problematic &pr);
			const Problematic *myself;
			int data;
	};

	std::ostream &operator<<(std::ostream &os, const Problematic &pr) {
		os << pr.get_data();
		return os;
	}

	std::istream &operator>>(std::istream &is, Problematic &pr) {
		assert(&pr == pr.myself);
		is >> pr.data;
		// Silly magic constant
		pr.data += 4711;
		return is;
	}
}

int main(int argc, char **argv) {
	std::ios::sync_with_stdio(false);
	string type;

	cin >> type; // row 1
	if(type == "int") {
		VectorTester<int> temp;
		temp.handle();
	} else if(type == "unsigned") {
		VectorTester<unsigned int> temp;
		temp.handle();
	} else if(type == "string") {
		VectorTester<std::string> temp;
		temp.handle();
	} else if(type == "problematic") {
		VectorTester<Problematic> temp;
		temp.handle();
	} else {
		assert(!"Unknown type");
	}

	return 0;
}
