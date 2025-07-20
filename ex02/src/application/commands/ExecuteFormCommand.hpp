/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExecuteFormCommand.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:02:52 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/19 22:19:41 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_FORM_COMMAND_HPP
#define EXECUTE_FORM_COMMAND_HPP

#include "domain/models/bureaucrat/Bureaucrat.hpp"
#include "domain/models/form/AForm.hpp"

class ExecuteFormCommand {
 public:
  ExecuteFormCommand(const AForm& form, const Bureaucrat& executor);
  ExecuteFormCommand(const ExecuteFormCommand& other);
  ~ExecuteFormCommand();

  ExecuteFormCommand& operator=(const ExecuteFormCommand& other);

  void execute() const;

 private:
  const AForm* m_form;
  const Bureaucrat* m_executor;

  void validateExecutionPreconditions() const;
  void performExecution() const;
  void handleExecutionSuccess() const;
  void logExecutionSuccess() const;
};

#endif // EXECUTE_FORM_COMMAND_HPP
