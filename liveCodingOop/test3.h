#pragma once

#include <exception>
#include <iostream>


class MyProjectException : public std::exception {
public:
	virtual char const* what() const override {
		return "My project exception";
	}
};

class BoardNotFoundException : public MyProjectException {
public:
	virtual char const* what() const override {
		return "Board exception";
	}
};

void test() {
	try {
		throw std::exception("exception");
		throw MyProjectException();
		throw BoardNotFoundException();
	}
	catch (BoardNotFoundException& e) {
		std::cout << e.what();
	}
	catch (MyProjectException& e) {
		std::cout << e.what();
	}
	catch (std::exception& e) {
		std::cout << e.what();
	}
}