/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:24:56 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/29 15:58:12 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "domain/models/form/AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm {
 public:
  ShrubberyCreationForm(const std::string& target);
  ShrubberyCreationForm(const ShrubberyCreationForm& other);
  ~ShrubberyCreationForm();

  ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

  virtual AForm* clone() const;
  void executeTask() const;

 private:
  static const std::string DEFAULT_FORM_NAME;
  static const int GRADE_TO_SIGN = 145;
  static const int GRADE_TO_EXECUTE = 137;
  std::string m_target;
};

#endif // SHRUBBERY_CREATION_FORM_HPP
