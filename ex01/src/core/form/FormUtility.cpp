/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FormUtility.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:38:34 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/05 20:42:26 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/bureaucrat/Bureaucrat.hpp"
#include "core/form/Form.hpp"
#include <iostream>
#include <ostream>
#include <string>

std::string Form::getName() const {
  return this->m_name;
}

int Form::getGradeToSign() const {
  return this->m_gradeToSign;
}

int Form::getGradeToExecute() const {
  return this->m_gradeToExecute;
}

bool Form::isSigned() const {
  return this->m_signed;
}

void Form::beSigned(Bureaucrat& bureaucrat) {
  if (bureaucrat.getGrade() > this->m_gradeToSign) {
    throw Form::GradeTooLowException();
  }
  this->m_signed = true;
  std::cout << "Bureaucrat " << bureaucrat.getName()
            << " signed form " << this->m_name << std::endl;
}

void Form::validateForm(int gradeToSign, int gradeToExecute) const {
  if (gradeToSign < LOWEST_GRADE || gradeToExecute < LOWEST_GRADE) {
    throw Form::GradeTooHighException();
  } else if (gradeToSign > HIGHEST_GRADE || gradeToExecute > HIGHEST_GRADE) {
    throw Form::GradeTooLowException();
  }
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
  return os << "Form, " << form.getName() << ", "
            << "Grade to Sign: " << form.getGradeToSign() << ", "
            << "Grade to Execute: " << form.getGradeToExecute() << ", "
            << "Status: " << (form.isSigned() ? "Signed" : "Unsigned");
}
