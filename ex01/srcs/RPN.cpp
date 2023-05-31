/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:11:14 by sleon             #+#    #+#             */
/*   Updated: 2023/05/31 13:23:24 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	calculate(std::string arg){
	std::istringstream	list(arg);
	std::stack<int>		_stack;
	int					check = 0;

	std::string	tmp;
	while (list >> tmp){
		std::stringstream	numbList(tmp);
		int					number = 0;
		int					_a;
		int					_b;

		if (numbList >> number){
			_stack.push(number);
			check++;
			if (check == 3){
				std::cout<<"Error : Too much consecutive digit in arg"<<std::endl;
				return 1;
			}
		}
		else if ((tmp.find("+") != std::string::npos || tmp.find("/") != std::string::npos
			|| tmp.find("*") != std::string::npos || tmp.find("-") != std::string::npos)
			&& _stack.size() > 1){
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
				if (_b == 0){
					std::cout<<"Error : cannot divide by 0"<<std::endl;
					return 1;}
				_stack.push(_a / _b);
			}
			else
				return (std::cout<<"Error : incorrect operator"<<std::endl, 1);
		}
		else{
			std::cout<<"Error : Invalid element in the argument pls use nbr and [/,*,-,+]"<<std::endl;
			return 1;
		}
	}
	std::cout<<_stack.top()<<std::endl;
	return 0;
}
