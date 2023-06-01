/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleon <sleon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 12:39:40 by sleon             #+#    #+#             */
/*   Updated: 2023/06/01 18:37:21 by sleon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	sorting(char **arg){
	std::vector<int>	nbrVector;
	std::list<int>		nbrList;
	double				timeVector = 0.00000;
	double				timeList = 0.00000;
	int					i = 0;
	int					nbr;

	std::clock_t start = clock();
	std::cout<<"Before : ";
	while (arg[i] != NULL){
	std::stringstream	iss(arg[i]);
		if (iss >> nbr)
			nbrVector.push_back(nbr);
		i++;
	}
	for (std::vector<int>::iterator it = nbrVector.begin(); it != nbrVector.end(); ++it)
		std::cout<<*it<<" ";
	std::cout<<std::endl;
	sortingVector(nbrVector, 0, nbrVector.size() - 1);
	std::clock_t end = clock();
	timeVector = (1000000.0 * (end - start)) / CLOCKS_PER_SEC;

	start = clock();
	i = 0;
	while (arg[i] != NULL){
		std::stringstream	iss(arg[i]);
		if (iss >> nbr)
			nbrList.push_back(nbr);
		i++;
	}
	sortingList(nbrList, nbrList.begin(), nbrList.end());
	std::cout<<"list done"<<std::endl;
	end = clock();
	timeList = (1000000.0 * (end - start)) / CLOCKS_PER_SEC;

	std::cout<<"After (vector) : ";
	for (std::vector<int>::iterator it = nbrVector.begin(); it != nbrVector.end(); ++it)
		std::cout<<*it<<" ";
	std::cout<<std::endl;
	std::cout<<"After (list): ";
    for (std::list<int>::iterator it = nbrList.begin(); it != nbrList.end(); ++it) {
        std::cout << *it << " ";
    }
	std::cout<<std::endl;
	std::cout<<"Time to process a range of "<<nbrVector.size()<<" elements with std::vector : "
	<<timeList<<"ms"<<std::endl;
	std::cout<<"Time to process a range of "<<nbrList.size()<<" elements with std::list : "
	<<timeVector<<"ms"<<std::endl;
	return 0;
}


void	vectorMerge(std::vector<int>& numbers, int a,  int b, int c){
	int	v1 = c - a + 1;
	int	v2= b - c;

	//formation de 2 sous vecteur temporaire
	std::vector<int> subV1(v1);
	for(int i = 0; i < v1; i++)
		subV1[i] = numbers[a + i];
	std::vector<int> subV2(v2);
	for (int i = 0; i < v2; i++)
		subV2[i] = numbers[c + 1 +i];

	//fusion des 2 sous vecteurs dans le vecteurs principal
	int	i = 0;
	int	j = 0;
	int	k = a;

	while (i < v1 && j < v2){
		if (subV1[i] <= subV2[j]){
			numbers[k] = subV1[i];
			i++;
		} else {
			numbers[k] = subV2[j];
			j++;
		}
		k++;
	}

	//copie des element restants
	while(i < v1){
		numbers[k] = subV1[i];
		i++;
		k++;
	}
	while(j < v2){
		numbers[k] = subV2[j];
		k++;
		j++;
	}
}

void	sortingVector(std::vector<int>&	nbrVector, int a, int b){
	if (a < b){
		int	c =(a + b) / 2;

		sortingVector(nbrVector, a, c);
		sortingVector(nbrVector, c + 1, b);
		vectorMerge(nbrVector, a, b, c);
	}
}

void	listMerge(std::list<int>& numbers, std::list<int>::iterator a, std::list<int>::iterator b, std::list<int>::iterator x){
	std::list<int>::iterator	it1 = a;
	std::list<int>::iterator	it2 = x;
	std::list<int>	merging;

	while (it1 != x && it2 != b){
		if (*it1 < *it2){
			merging.push_back(*it1);
			std::cout<<"cela est push it1: "<<*it1<<std::endl;
			it1++;
		} else if (*it2 < *it1){
			merging.push_back(*it2);
			std::cout<<"cela est push en it2: "<<*it2<<std::endl;
			it2++;
		} else {
			merging.push_back(*it1);
			merging.push_back(*it2);
			std::cout<<"cela est push : "<<*it1<<" ET "<<*it2<<std::endl;
			it1++;
			it2++;
		}
	}

	//copie des element restants
	while(it1 != x){
		merging.push_back(*it1);
		it1++;
	}
	while(it2 != b){
		merging.push_back(*it2);
		it2++;
	}

	// for(std::list<int>::iterator i = merging.begin(); i != merging.end(); i++){
	// 	std::cout<<"ca est push : "<<*i<<std::endl;
	// 	numbers.push_back(*i);
	// }
	(void)numbers;
	std::list<int>::iterator mergeIt = merging.begin();
	while (a != b) {
		*a = *mergeIt;
		a++;
		mergeIt++;
	}
}


void	sortingList(std::list<int>&	nbrList, std::list<int>::iterator a,
	std::list<int>::iterator b){
	std::list<int>::iterator	x;
	int							dist = 0;
	int							dist2 = 0;

	x = a;
	--b;
	while (x != b){
		x++;
		dist++;
		}
	if (dist > 1 && x != nbrList.end()){
		x = a;
		while ((dist/2) !=  dist2){
			x++;
			dist2++;
		}
		sortingList(nbrList, a, x);
		sortingList(nbrList, ++x, b);
		listMerge(nbrList, a, b, --x);
	}
}
