/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExecuteFormCommandUtility.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 23:04:35 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/19 23:05:25 by dande-je         ###   ########.fr       */
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
      throw AForm::AFormNotSignedException();
    }
    if (this->m_form->isExecuted()) {
      throw AForm::AFormExecutedException();
    }
  }

  if (!this->m_form->canBeExecutedBy(*this->m_executor)) {
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
                          " executed form " + this->m_form->getName();
  StreamWriter::print(GREEN, msg);
}
