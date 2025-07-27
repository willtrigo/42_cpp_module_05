/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:14:52 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/27 14:05:07 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "domain/models/bureaucrat/Bureaucrat.hpp"
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

  class FormNotSignedException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

  Form(const std::string& name, int gradeToSign, int gradeToExecute);
  Form(const Form& other);
  ~Form();

  Form& operator=(const Form& other);

  const std::string getName() const throw();
  int getGradeToSign() const throw();
  int getGradeToExecute() const throw();
  bool isSigned() const throw();
  bool isExecuted() const throw();

  void markAsSigned() const throw();

  void beSigned(Bureaucrat& bureaucrat);
  bool canBeSignedBy(const Bureaucrat& executor) const throw();
  bool isValidForSign() const throw();

 private:
  static const int HIGHEST_GRADE = 150;
  static const int LOWEST_GRADE = 1;

  mutable bool m_signed;
  mutable bool m_executed;

  const std::string m_name;
  const int m_gradeToSign;
  const int m_gradeToExecute;

  void validateForm(int gradeToSign, int gradeToExecute) const;
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif // FORM_HPP
