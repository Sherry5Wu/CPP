/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jingwu <jingwu@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 10:02:46 by jingwu            #+#    #+#             */
/*   Updated: 2025/04/07 10:31:18 by jingwu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}

RPN::~RPN(){}

/**
 * @brief Using std::istringstream and std::getline to get each token ('8', '*'...)
 * saving into token, the delimiter is one space. Then checking:
 *   * if the token is empty---> throw error meassage;
 *   * if it is a operator ---> go to calculate;
 *   * if it is a digit ----> push into the stack
 *
 */
void	RPN::calculateResult(const std::string& expression){
	if (expression.empty()){
		throw (std::runtime_error("Error: expression is empty"));
	}

	std::istringstream expr_stream(expression);
	std::string token;
	std::string operators = "+-*/";

	// (std::getline(expr_stream, token, ' '): using space as delimiter
	// every time read one token from expr_stream saving in token.
	while (std::getline(expr_stream, token, ' ')){
		if (token.empty()){
			throw (std::runtime_error("Error: expression format is wrong"));
		} else if (token.length() == 1 && operators.find(token) != std::string::npos){ // checking if it is a operator
			calculator(token);
		} else if (token.length() == 1 && std::isdigit(token[0])){ // checking if it is a digit
			stack_.push(std::stoi(token));
		} else {
			throw (std::runtime_error("Error"));
		}
	}
	if (stack_.size() != 1){
		throw (std::runtime_error("Error: invalid expression"));
	}
	std::cout << stack_.top() << std::endl;
}

/**
 * @brief After getting the top element in the stack, then pop it out
 * of the stack
 */
int	topNumber(std::stack<int>& stack){
	int	top = stack.top();
	stack.pop();
	return top;
}

void	RPN::calculator(std::string& ope){
	if (stack_.size() < 2){
		throw (std::runtime_error("Error: invalid expression," + ope +" missing operands"));
	}
	int	b = topNumber(stack_); // the first pop number is the second operand number
	int a = topNumber(stack_);
	if (ope == "+"){
		stack_.push(a + b);
	} else if (ope == "-"){
		stack_.push(a - b);
	}else if (ope == "*"){
		stack_.push(a * b);
	}else{
		if (b == 0){
			throw(std::runtime_error("Error: the dividend can't be 0"));
		}
		stack_.push(a / b);
	}
}

// for debugging
// void	RPN::printStack(){
// 	std::cout << std::endl << "Stack: ";
// 	while (stack_.size() != 0){
// 		std::cout << stack_.top();
// 		stack_.pop();
// 	}
// 	std::cout << std::endl;
// }
