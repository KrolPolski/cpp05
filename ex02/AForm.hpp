/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:33:54 by rboudwin          #+#    #+#             */
/*   Updated: 2024/11/08 17:33:05 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;
class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned {false};
		const int			_gradeToSign;
		const int			_gradeToExecute;
	public:
	class GradeTooHighException : public std::exception
	{
		public:
			GradeTooHighException() = default;
			virtual const char *what() const noexcept;
			~GradeTooHighException() = default;
	};
	
	class GradeTooLowException : public std::exception
	{
		public:
			GradeTooLowException() = default;
			virtual const char *what() const noexcept;
			~GradeTooLowException() = default;
	};
	class FormNotSignedException : public std::exception
	{
		public:
			FormNotSignedException() = default;
			virtual const char *what() const noexcept;
			~FormNotSignedException() = default;
	};
		AForm();
		AForm(std::string name, int toSign, int toExecute);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other) = delete;
		int getGradeToSign() const; 
		int getGradeToExecute() const;
		bool getIsSigned() const;
		const std::string getName() const;
		void beSigned(Bureaucrat& drone);
		virtual void execute(Bureaucrat const& executor) const = 0;
		virtual ~AForm();
};

std::ostream& operator<<(std::ostream& out, const AForm& someAForm);