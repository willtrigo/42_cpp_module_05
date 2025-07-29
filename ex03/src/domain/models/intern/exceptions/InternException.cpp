/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InternException.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 18:28:38 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/29 19:01:28 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domain/models/intern/Intern.hpp"

const char* Intern::InvalidFormException::what() const throw() {
  return "Error: this type of form does not exist";
}
