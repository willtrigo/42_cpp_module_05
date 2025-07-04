/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:38:26 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/04 20:38:43 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "core/bureaucrat/Bureaucrat.hpp"
#include <exception>
#include <string>

class Form {
 public:
  class GradeTooHighException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

  class FormSignedException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

  Form(const std::string& name, int gradeToSign, int gradeToExecute);
  Form(const Form& other);
  Form& operator=(const Form& other);
  ~Form();

  std::string getName() const;
  int getGradeToSign() const;
  int getGradeToExecute() const;
  bool isSigned() const;

  void beSigned(Bureaucrat& bureaucrat);

 private:
  Form();

  static const std::string DEFAULT_FORM_NAME;
  static const int DEFAULT_GRADE_TO_EXECUTE = 150;
  static const int DEFAULT_GRADE_TO_SIGN = 150;
  static const int HIGHEST_GRADE = 150;
  static const int LOWEST_GRADE = 1;
  const std::string m_name;
  const int m_gradeToSign;
  const int m_gradeToExecute;
  bool m_signed;

  void validateForm(int gradeToSign, int gradeToExecute) const;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif // FORM_HPP
