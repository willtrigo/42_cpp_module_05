/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExecuteFormCommand.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:07:26 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/29 15:55:06 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "application/commands/ExecuteFormCommand.hpp"
#include "domain/models/bureaucrat/Bureaucrat.hpp"
#include "domain/models/form/AForm.hpp"

ExecuteFormCommand::ExecuteFormCommand(const AForm& form, const Bureaucrat& executor)
  : m_form(&form),
    m_executor(&executor) {}

ExecuteFormCommand::ExecuteFormCommand(const ExecuteFormCommand& other)
  : m_form(other.m_form),
    m_executor(other.m_executor) {}

ExecuteFormCommand::~ExecuteFormCommand() {}

ExecuteFormCommand& ExecuteFormCommand::operator=(const ExecuteFormCommand& other) {
  if (this != &other) {
    this->m_form = other.m_form;
    this->m_executor = other.m_executor;
  }
  return *this;
}
