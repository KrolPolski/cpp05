/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:01:13 by rboudwin          #+#    #+#             */
/*   Updated: 2024/11/08 17:35:10 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	//Confirm abstract form:
	//AForm test;
	Bureaucrat drone;
	ShrubberyCreationForm test;
	std::cout << "We have made a Shrubbery form and a drone. Woo.\nThe drone shouldn't be able to execute this form because it hasn't been signed yet." << std::endl;
	try
	{
		drone.executeForm(test);
	}
	catch (const AForm::FormNotSignedException& e)
	{
		std::cout << e.what() << std::endl;
	}
	Bureaucrat SirRobin("Sir Robin", 145);
	std::cout << SirRobin.getName() << " should be able to sign it, but not execute it since his grade is "	<< SirRobin.getGrade() << std::endl;
	SirRobin.signForm(test);
	try
	{
		SirRobin.executeForm(test);
	}
	catch (const AForm::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
	Bureaucrat SirLancelot("Sir Lancelot", 100);
	SirLancelot.executeForm(test);
}