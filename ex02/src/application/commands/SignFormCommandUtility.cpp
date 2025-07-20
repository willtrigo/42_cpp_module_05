/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SignFormCommandUtility.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 23:17:24 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/20 01:00:06 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "application/commands/SignFormCommand.hpp"
#include "domain/models/form/AForm.hpp"
#include "infrastructure/io/StreamWriter.hpp"
#include "infrastructure/utils/TerminalColor.hpp"

void SignFormCommand::execute() const {
  this->validateSignPreconditions();
  this->performSign();
  this->handleSignSuccess();
}

void SignFormCommand::validateSignPreconditions() const {
  if (!this->m_form->isValidForSign()) {
    throw AForm::AFormSignedException();
  }

  if (this->m_form->isExecuted()) {
    throw AForm::AFormExecutedException();
  }

  if (!this->m_form->canBeSignedBy(*this->m_executor)) {
    throw AForm::GradeTooLowException();
  }
}

void SignFormCommand::performSign() const {
  this->m_form->markAsSigned();
}

void SignFormCommand::handleSignSuccess() const {
  this->logSignSuccess();
}

void SignFormCommand::logSignSuccess() const {
  const std::string msg = "Bureaucrat " + this->m_executor->getName() +
                          " signed " + this->m_form->getName();
  StreamWriter::print(CYAN, msg);
}
