/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rboudwin <rboudwin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:33:54 by rboudwin          #+#    #+#             */
/*   Updated: 2024/11/08 14:02:20 by rboudwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
class Form
{
	private:
		const std::string	_name;
		bool				_isSigned {false};
		const int			_gradeToSign;
		const int			_gradeToExecute;
	public:
	class GradeTooHighException : std::exception
	{
		public:
			GradeTooHighException() = default;
			virtual const char *what() const noexcept;
			~GradeTooHighException() = default;
	};
	
	class GradeTooLowException : std::exception
	{
		public:
			GradeTooLowException() = default;
			virtual const char *what() const noexcept;
			~GradeTooLowException() = default;
	};
		Form();
		Form(std::string name, int toSign, int toExecute);
		Form(const Form& other);
		Form& operator=(const Form& other) = delete;
		const int getGradeToSign();
		const int getGradeToExecute();
		bool getIsSigned();
		const std::string getName();
		~Form();
};