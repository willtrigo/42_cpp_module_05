/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SignFormCommand.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:07:58 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/29 15:56:00 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGN_FORM_COMMAND_HPP
#define SIGN_FORM_COMMAND_HPP

#include "domain/models/bureaucrat/Bureaucrat.hpp"
#include "domain/models/form/AForm.hpp"

class SignFormCommand {
 public:
  SignFormCommand(const AForm& form, const Bureaucrat& executor);
  SignFormCommand(const SignFormCommand& other);
  ~SignFormCommand();

  SignFormCommand& operator=(const SignFormCommand& other);

  void execute() const;

 private:
  const AForm* m_form;
  const Bureaucrat* m_executor;

  void validateSignPreconditions() const;
  void performSign() const;
  void handleSignSuccess() const;
  void logSignSuccess() const;
};

#endif // SIGN_FORM_COMMAND_HPP
