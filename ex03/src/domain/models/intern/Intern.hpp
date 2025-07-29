/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 16:23:49 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/29 18:27:31 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "domain/models/form/AForm.hpp"
#include <exception>
#include <string>

class Intern {
 public:
  class InvalidFormException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

  Intern();
  Intern(const Intern&);
  ~Intern();

  Intern& operator=(const Intern&);

  AForm* makeForm(const std::string& formName, const std::string& target) const;

 private:
  typedef AForm* (Intern::*FormCreator)(const std::string& target) const;

  struct FormMap {
    std::string formName;
    FormCreator creator;
  };

  static const FormMap m_formMap[TOTAL_FORMS];

  AForm* createShrubberyCreationForm(const std::string& target) const;
  AForm* createRobotomyRequestForm(const std::string& target) const;
  AForm* createPresidentialPardonForm(const std::string& target) const;
};

#endif // INTERN_HPP
