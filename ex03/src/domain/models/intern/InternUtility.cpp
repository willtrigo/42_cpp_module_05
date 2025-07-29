/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InternUtility.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 17:16:39 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/29 19:04:28 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domain/models/form/AForm.hpp"
#include "domain/models/form/creations/shrubbery/ShrubberyCreationForm.hpp"
#include "domain/models/form/requests/presidential/PresidentialPardonForm.hpp"
#include "domain/models/form/requests/robotomy/RobotomyRequestForm.hpp"
#include "domain/models/intern/Intern.hpp"
#include "infrastructure/io/StreamWriter.hpp"
#include "infrastructure/utils/TerminalColor.hpp"
#include <string>

const Intern::FormMap Intern::m_formMap[TOTAL_FORMS] = {
{"shrubbery creation", &Intern::createShrubberyCreationForm},
{"robotomy request", &Intern::createRobotomyRequestForm},
{"presidential pardon", &Intern::createPresidentialPardonForm}
};

AForm* Intern::createShrubberyCreationForm(const std::string& target) const {
  return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target) const {
  return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) const {
  return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const {
  for (int i = 0; i < TOTAL_FORMS; ++i) {
    if (m_formMap[i].formName == formName) {
      StreamWriter::print(WHITE, BG_ORANGE, "Intern creates " + formName);
      return (this->*(m_formMap[i].creator))(target);
    }
  }
  StreamWriter::print(RED, "Intern try to create " + formName);
  throw Intern::InvalidFormException();
}
