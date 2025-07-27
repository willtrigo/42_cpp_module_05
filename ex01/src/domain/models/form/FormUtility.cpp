/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FormUtility.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:14:48 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/27 13:23:49 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "application/commands/SignFormCommand.hpp"
#include "domain/models/bureaucrat/Bureaucrat.hpp"
#include "domain/models/form/Form.hpp"
#include "infrastructure/io/FormPrinter.hpp"
#include <iostream>
#include <string>

const std::string Form::getName() const throw() {
  return this->m_name;
}

int Form::getGradeToSign() const throw() {
  return this->m_gradeToSign;
}

int Form::getGradeToExecute() const throw() {
  return this->m_gradeToExecute;
}

bool Form::isSigned() const throw() {
  return this->m_signed;
}

bool Form::isExecuted() const throw() {
  return this->m_executed;
}

void Form::markAsSigned() const throw() {
  this->m_signed = true;
}

void Form::beSigned(Bureaucrat& bureaucrat) {
  SignFormCommand form(*this, bureaucrat);
  form.execute();
  // if (bureaucrat.getGrade() > this->m_gradeToSign) {
  //   throw Form::GradeTooLowException();
  // }
  // if (this->m_signed) {
  //   throw Form::FormSignedException();
  // }
  // this->m_signed = true;
  // std::cout << "Bureaucrat " << bureaucrat.getName()
  //           << " signed form " << this->m_name << std::endl;
}

void Form::validateForm(int gradeToSign, int gradeToExecute) const {
  if (gradeToSign < LOWEST_GRADE || gradeToExecute < LOWEST_GRADE) {
    throw Form::GradeTooHighException();
  } else if (gradeToSign > HIGHEST_GRADE || gradeToExecute > HIGHEST_GRADE) {
    throw Form::GradeTooLowException();
  }
}

bool Form::canBeSignedBy(const Bureaucrat& executor) const throw() {
  return executor.getGrade() <= this->m_gradeToSign;
}

bool Form::isValidForSign() const throw() {
  return !this->m_signed;
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
  return FormPrinter::print(os, form);
}
