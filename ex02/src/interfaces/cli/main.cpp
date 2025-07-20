/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:38:42 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/19 22:49:01 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domain/models/bureaucrat/Bureaucrat.hpp"
#include "domain/models/form/AForm.hpp"
#include "domain/models/form/creations/shrubbery/ShrubberyCreationForm.hpp"
#include "domain/models/form/requests/presidential/PresidentialPardonForm.hpp"
#include "domain/models/form/requests/robotomy/RobotomyRequestForm.hpp"
#include "infrastructure/io/BureaucratPrinter.hpp"
#include "infrastructure/utils/TerminalColor.hpp"
#include "interfaces/testing/TestHelpers.hpp"
#include <cstdlib>

int main() {
	try {
    Bureaucrat boss("Boss", 1);
    BureaucratPrinter::print(std::cout, boss);

    AForm *form_pardon = new PresidentialPardonForm("Will Trigo");
    form_pardon->beSigned(boss);
    form_pardon->execute(boss);

    AForm *form_robotomy = new RobotomyRequestForm("Staff");
    form_robotomy->beSigned(boss);
    form_robotomy->execute(boss);
    form_robotomy->execute(boss);
    form_robotomy->execute(boss);

    AForm *form_shrunbbery = new ShrubberyCreationForm("home");
    form_shrunbbery->beSigned(boss);
    form_shrunbbery->execute(boss);
	} catch (const std::exception& e) {
    testHelperLog(ORANGE, "Caught unexpected exception:");
    testHelperLog(RED, e.what());
	}
  return EXIT_SUCCESS;
}
