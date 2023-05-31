/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:11:14 by sleon             #+#    #+#             */
/*   Updated: 2023/05/31 12:30:12 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){
	std::cout<<"RPN constructor called"<<std::endl;
}

RPN::RPN(RPN const &toCopy){
	if (this != &toCopy)
		*this = toCopy;
	std::cout<<"RPN copy constructor called"<<std::endl;
}

RPN::~RPN(){
	std::cout<<"RPN destructor called"<<std::endl;
}

RPN& RPN::operator=(RPN const &toCopy){
	// _stack.insert(toCopy._stack.begin(), toCopy._stack.end());
	(void)toCopy;
	return (*this);
}

int	RPN::calculate(std::string arg){
	std::istringstream	list(arg);

	std::string	tmp;
	while (list >> tmp){
		std::stringstream	numbList(tmp);
		int					number;
		int					check = 0;

		if (numbList >> number){
			_stack.push(number);
			check++;
			if (check == 3){
				std::cout<<"Error : Too much consecutive digit in arg"<<std::endl;
				return 1;
			}
		}
		else if (tmp.find("+") != std::string::npos || tmp.find("/") != std::string::npos
			|| tmp.find("*") != std::string::npos || tmp.find("-") != std::string::npos){
			_b = _stack.top();
			_stack.pop();
			_a = _stack.top();
			_stack.pop();
			if (tmp == "+"){
				check = 0;
				_stack.push(_a + _b);
			}
			else if (tmp == "-"){
				check = 0;
				_stack.push(_a - _b);
			}
			else if (tmp == "*"){
				check = 0;
				_stack.push(_a * _b);
			}
			else if (tmp == "/"){
				check = 0;
				_stack.push(_a / _b);
			}
		}
		else{
			std::cout<<"Error : Invalid element in the argument pls use nbr and [/,*,-,+]"<<std::endl;
			return 1;
		}
	}
	std::cout<<_stack.top()<<std::endl;
	return 0;
}
