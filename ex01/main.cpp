/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:01:13 by rboudwin          #+#    #+#             */
/*   Updated: 2024/11/08 15:10:59 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat	Tim("Tim", 10);
	Bureaucrat	drone;
	Form		EvilLicense("License for Evil", 11, 11);

	std::cout << EvilLicense << std::endl;
	
	std::cout << "Let's make some invalid forms" << std::endl;
	
	try
	{
		Form		ImpossibleForm("ImpossibleForm", 0, -1);
	}
	catch(const Form::GradeTooHighException& e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Form		EasyForm("EasyForm", 150, 151);
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl << "Time to fail at signing a form" << std::endl;
	drone.signForm(EvilLicense);
	std::cout << std::endl << "But Tim is sufficiently fancy" << std::endl;
	Tim.signForm(EvilLicense);
	std::cout << "But even Tim isn't fancy enough to sign it twice" << std::endl;
	Tim.signForm(EvilLicense);
}