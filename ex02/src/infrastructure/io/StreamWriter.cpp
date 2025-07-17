/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StreamWriter.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:46:57 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/17 18:18:49 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "infrastructure/io/StreamWriter.hpp"
#include <iostream>

StreamWriter::StreamWriter() {}

StreamWriter::StreamWriter(const StreamWriter& other) {
  (void)other;
}

StreamWriter& StreamWriter::operator=(const StreamWriter& other) {
  (void)other;
  return *this;
}

StreamWriter::~StreamWriter() {}

void StreamWriter::print(StrColor strColor, const std::string &str) {
  (void) strColor;
  std::cout << str;
}

void StreamWriter::print(StrColor strColor, BgColor bgColor, const std::string &str) {
  (void)strColor;
  (void)bgColor;
  std::cout << str;
}
