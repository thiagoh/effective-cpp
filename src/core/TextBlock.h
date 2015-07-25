/*
 * TextBlock.cpp
 *
 *  Created on: Jul 23, 2015
 *      Author: thiago
 */

#include <stddef.h>
#include <string>

class TextBlock {
public:
	TextBlock(std::string s) {
		this->text = s;
	};
    const char& operator[](std::size_t pos) const {
        return text[pos];
    };
    char& operator[](std::size_t pos) {
        return text[pos];
    };

private:
    std::string text;
};
