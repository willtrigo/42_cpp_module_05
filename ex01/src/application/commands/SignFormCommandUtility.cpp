/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SignFormCommandUtility.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:11:26 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/27 13:27:58 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "application/commands/SignFormCommand.hpp"
#include "domain/models/form/Form.hpp"
#include "infrastructure/io/StreamWriter.hpp"
#include "infrastructure/utils/TerminalColor.hpp"

void SignFormCommand::execute() const {
  this->validateSignPreconditions();
  this->performSign();
  this->handleSignSuccess();
}

void SignFormCommand::validateSignPreconditions() const {
  if (!this->m_form->isValidForSign()) {
    StreamWriter::print(RED, this->m_executor->getName() + " couldn't sign " + this->m_form->getName() + " because:");
    throw Form::FormSignedException();
  }

  if (!this->m_form->canBeSignedBy(*this->m_executor)) {
    StreamWriter::print(RED, this->m_executor->getName() + " couldn't sign " + this->m_form->getName() + " because:");
    throw Form::GradeTooLowException();
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
