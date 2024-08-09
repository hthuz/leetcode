
#include <iostream>
#include <string>
using namespace std;
class Trie{
	private:
		Trie* children[26];
		bool isword;
	public:
		Trie() {
			isword = false;
			for (int i = 0; i < 26; i++) {
				children[i] = nullptr;
			}
		}
		void insert(string word) {
			if (this->children[word[0] - 'a'] == nullptr) {
				this->children[word[0] - 'a'] = new Trie();
			}
			if (word.length() == 1) {
				this->children[word[0] - 'a']->isword = true;
				return;
			}
			this->children[word[0] - 'a']->insert(word.substr(1, word.length() - 1));
		}
		bool search(string word) {
			if (this->children[word[0] - 'a'] == nullptr)
				return false;
			if (word.length() == 1) 
				return this->children[word[0] - 'a']->isword;
			return this->children[word[0] - 'a']->search(word.substr(1, word.length() - 1));
		}
		bool startsWith(string prefix) {
			if (this->children[prefix[0] - 'a'] == nullptr)
				return false;
			if (prefix.length() == 1)
				return true;
			return this->children[prefix[0] - 'a']->startsWith(prefix.substr(1,prefix.length() - 1));
		}
};


int main() {
	Trie* obj = new Trie();
	obj->insert("apple");
	cout << obj->search("apple") << endl;
	cout << obj->search("app") << endl;
	cout << obj->startsWith("app") << endl;
	obj->insert("app");
	cout << obj->search("app") << endl;

}
