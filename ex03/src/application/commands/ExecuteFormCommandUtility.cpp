/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExecuteFormCommandUtility.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:07:33 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/29 15:55:36 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "application/commands/ExecuteFormCommand.hpp"
#include "infrastructure/io/StreamWriter.hpp"
#include "infrastructure/utils/TerminalColor.hpp"
#include <string>

void ExecuteFormCommand::execute() const {
  this->validateExecutionPreconditions();
  this->performExecution();
  this->handleExecutionSuccess();
}

void ExecuteFormCommand::validateExecutionPreconditions() const {
  if (!this->m_form->isValidForExecution()) {
    if (!this->m_form->isSigned()) {
      StreamWriter::print(RED, this->m_executor->getName() + " couldn't execute " + this->m_form->getName() + " because:");
      throw AForm::AFormNotSignedException();
    }
    if (this->m_form->isExecuted()) {
      StreamWriter::print(RED, this->m_executor->getName() + " couldn't execute " + this->m_form->getName() + " because:");
      throw AForm::AFormExecutedException();
    }
  }

  if (!this->m_form->canBeExecutedBy(*this->m_executor)) {
    StreamWriter::print(RED, this->m_executor->getName() + " couldn't execute " + this->m_form->getName() + " because:");
    throw AForm::GradeTooLowException();
  }
}

void ExecuteFormCommand::performExecution() const {
  this->m_form->executeTask();
} 

void ExecuteFormCommand::handleExecutionSuccess() const {
  this->logExecutionSuccess();
}

void ExecuteFormCommand::logExecutionSuccess() const {
  const std::string msg = "Bureaucrat " + this->m_executor->getName() +
                          " executed " + this->m_form->getName();
  StreamWriter::print(BLUE, msg);
}
