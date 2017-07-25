// 604. Design Compressed String Iterator - https://leetcode.com/problems/design-compressed-string-iterator

class StringIterator {
    istringstream iss;
    char ch;
    int count;
public:
    StringIterator(string compressedString) {
        iss = istringstream(compressedString);
        count = ch = 0;
    }

    char next() {
        if (hasNext()) {
            --count;
            return ch;
        } else {
            return ' ';
        }
    }

    bool hasNext() {
        if (count == 0) {
            iss >> ch >> count;
        }
        return count > 0;
    }
};