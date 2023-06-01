/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:39:35 by sleon             #+#    #+#             */
/*   Updated: 2023/06/01 19:10:14 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <sstream>
# include <vector>
# include <list>
# include <ctime>
# include <algorithm>

int		sorting (char **arg);
void	vectorMerge(std::vector<int>& numbers, int a,  int b, int c);
void	sortingVector(std::vector<int>&	nbrVector, int a, int b);
void	sortingList(std::list<int>&	nbrList, std::list<int>::iterator a, std::list<int>::iterator b);
void	listMerge(std::list<int> numbers, int a,  int b, int c);
bool	isSorted(std::list<int>& nbrList);

#endif
