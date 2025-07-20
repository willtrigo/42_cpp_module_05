/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationFormUtility.cpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 15:09:51 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/19 22:17:28 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domain/models/form/creations/shrubbery/ShrubberyCreationForm.hpp"
#include "infrastructure/file/FileWriter.hpp"
#include "infrastructure/io/StreamWriter.hpp"
#include "infrastructure/utils/TerminalColor.hpp"
#include <string>

void ShrubberyCreationForm::executeTask() const {
  std::string filename = this->m_target + "_shrubbery";
  std::string tree = 
    "       _-_\n"
    "    /~~   ~~\\\n"
    " /~~         ~~\\\n"
    "{               }\n"
    " \\  _-     -_  /\n"
    "   ~  \\\\ //  ~\n"
    "_- -   | | _- _\n"
    "  _ -  | |   -_\n"
    "      // \\\\\n"
    "\n"
    "The tree by shrubbery";

  FileWriter::writeToFile(filename, tree);
  StreamWriter::print(BLACK, BG_WHITE, "Shrubbery creates " + filename);
  this->markAsExecuted();
}
