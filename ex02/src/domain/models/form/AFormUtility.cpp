/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AFormUtility.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:43:11 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/18 16:01:04 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domain/models/bureaucrat/Bureaucrat.hpp"
#include "domain/models/form/AForm.hpp"
#include "infrastructure/io/StreamWriter.hpp"
#include "infrastructure/utils/TerminalColor.hpp"
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

void AForm::beSigned(Bureaucrat& bureaucrat) {
  if (bureaucrat.getGrade() > this->m_gradeToSign) {
    throw AForm::GradeTooLowException();
  } else if (this->m_signed) {
    throw AForm::AFormSignedException();
  }
  this->m_signed = true;
  StreamWriter::print(BLUE, "Bureaucrat " + bureaucrat.getName() +
                      " signed form " + this->getName());
}

void AForm::validateAForm(int gradeToSign, int gradeToExecute) const {
  if (gradeToSign < LOWEST_GRADE || gradeToExecute < LOWEST_GRADE) {
    throw AForm::GradeTooHighException();
  } else if (gradeToSign > HIGHEST_GRADE || gradeToExecute > HIGHEST_GRADE) {
    throw AForm::GradeTooLowException();
  }
}

void AForm::execute(const Bureaucrat& executor) const {
  if (!this->isSigned()) {
    throw AForm::AFormNotSignedException();
  } else if (executor.getGrade() > this->getGradeToExecute()) {
    throw AForm::GradeTooLowException();
  } else if (this->isExecuted()) {
    throw AForm::AFormExecutedException();
  }
  this->executeTask();
}
