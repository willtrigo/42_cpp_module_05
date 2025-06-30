/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 15:33:22 by dande-je          #+#    #+#             */
/*   Updated: 2025/06/30 15:33:30 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <string>

class Bureaucrat {
 public:
  class GradeTooHighException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

  Bureaucrat();
  Bureaucrat(const std::string& name, int grade);
  Bureaucrat(const Bureaucrat& other);
  Bureaucrat& operator=(const Bureaucrat& other);
  ~Bureaucrat();

  std::string getName() const;
  int getGrade() const;

  void incrementGrade();
  void decrementGrade();

 private:
  const std::string m_name;
  int m_grade;

  static const std::string DEFAULT_NAME;
  static const int DEFAULT_GRADE;
  static const int HIGHEST_GRADE;
  static const int LOWEST_GRADE;

  void validateGrade(int grade) const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& Bureaucrat);

#endif // BUREAUCRAT_HPP
