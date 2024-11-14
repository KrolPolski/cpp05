/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:01:13 by rboudwin          #+#    #+#             */
/*   Updated: 2024/11/14 09:48:32 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <ctime>

int main(void)
{
	//ensures we have a new random seed each time we run
	srand(static_cast<unsigned int>(time(0)));
	
	Intern		Brad;
	AForm		*shrubPtr;
	AForm		*robotPtr;
	AForm		*pardonPtr;
	AForm		*nonsensePtr;
	Bureaucrat	MrPrez("Mr. President", 1);

	shrubPtr = Brad.makeForm("shrubbery creation", "TheKnightsWhoSayNi");
	robotPtr = Brad.makeForm("robotomy request", "Bender");
	pardonPtr = Brad.makeForm("presidential pardon", "ConvictedFelon");
	nonsensePtr = Brad.makeForm("king me", "Mr. President");
	
	MrPrez.signForm(*shrubPtr);
	MrPrez.executeForm(*shrubPtr);
	MrPrez.signForm(*robotPtr);
	MrPrez.executeForm(*robotPtr);
	MrPrez.signForm(*pardonPtr);
	MrPrez.executeForm(*pardonPtr);

	delete shrubPtr;
	delete robotPtr;
	delete pardonPtr;
}