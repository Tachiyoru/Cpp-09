/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:11:16 by sleon             #+#    #+#             */
/*   Updated: 2023/05/31 12:19:14 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <sstream>
# include <stack>

class RPN
{
	private:

		std::stack<int>	_stack;
		int				_a;
		int				_b;

	public:

		RPN();
		RPN(RPN const &copy);
		~RPN();

		RPN	&operator=(RPN const &toCopy);

		int	calculate(std::string);
};

#endif
