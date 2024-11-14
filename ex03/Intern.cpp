/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:07:05 by rboudwin          #+#    #+#             */
/*   Updated: 2024/11/14 09:52:02 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"


Intern::Intern(/* args */)
{
}

Intern::~Intern()
{
}

Intern::Intern(const Intern& other)
{
	(void) other;	
}

Intern& Intern::operator=(const Intern& other)
{
	(void) other;	
	return (*this);
}

AForm *Intern::makeForm(std::string formName, std::string formTarget)
{
	std::string formNames[3] {"robotomy request", "presidential pardon", "shrubbery creation"};
	int 		i = 0;
	AForm		*formPtr;

	while (i < 3 && formName != formNames[i])
		i++;

	switch (i)
	{
	case 0:
	{
		formPtr = new RobotomyRequestForm(formTarget);
		std::cout << "Intern creates a Robotomy Request Form." << std::endl;
		return formPtr;
	}
	case 1:
	{
		formPtr = new PresidentialPardonForm(formTarget);
		std::cout << "Intern creates a Presidential Pardon Form."<< std::endl;
		return formPtr;
	}
	case 2:
	{
		formPtr = new ShrubberyCreationForm(formTarget);
		std::cout << "Intern creates a Shrubbery Creation Form." << std::endl;
		return formPtr;
	}
	default:
		std::cerr << formName << " is not a valid form name." << std::endl;
		return nullptr;
	}
}