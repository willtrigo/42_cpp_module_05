/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AFormUtility.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:43:11 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/26 21:22:05 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "application/commands/ExecuteFormCommand.hpp"
#include "application/commands/SignFormCommand.hpp"
#include "domain/models/bureaucrat/Bureaucrat.hpp"
#include "domain/models/form/AForm.hpp"
#include "infrastructure/io/FormPrinter.hpp"
#include <iostream>
#include <string>

const std::string AForm::getName() const throw() {
  return this->m_name;
}

int AForm::getGradeToSign() const throw() {
  return this->m_gradeToSign;
}

int AForm::getGradeToExecute() const throw() {
  return this->m_gradeToExecute;
}

bool AForm::isSigned() const throw() {
  return this->m_signed;
}

bool AForm::isExecuted() const throw() {
  return this->m_executed;
}

void AForm::markAsSigned() const throw() {
  this->m_signed = true;
}

void AForm::markAsExecuted() const throw() {
  this->m_executed = true;
}

void AForm::beSigned(Bureaucrat& bureaucrat) {
  SignFormCommand form(*this, bureaucrat);
  form.execute();
}

void AForm::validateAForm(int gradeToSign, int gradeToExecute) const {
  if (gradeToSign < LOWEST_GRADE || gradeToExecute < LOWEST_GRADE) {
    throw AForm::GradeTooHighException();
  } else if (gradeToSign > HIGHEST_GRADE || gradeToExecute > HIGHEST_GRADE) {
    throw AForm::GradeTooLowException();
  }
}

bool AForm::canBeSignedBy(const Bureaucrat& executor) const throw() {
  return executor.getGrade() <= this->m_gradeToSign;
}

bool AForm::canBeExecutedBy(const Bureaucrat& executor) const throw() {
  return executor.getGrade() <= this->m_gradeToExecute;
}

bool AForm::isValidForSign() const throw() {
  return !this->m_signed;
}

bool AForm::isValidForExecution() const throw() {
  return this->m_signed && !this->m_executed;
}

void AForm::execute(const Bureaucrat& executor) const {
  ExecuteFormCommand form(*this, executor);
  form.execute();
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
  return FormPrinter::print(os, form);
}
