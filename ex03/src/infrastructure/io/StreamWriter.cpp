/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StreamWriter.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:35:46 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/29 16:02:57 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infrastructure/io/StreamWriter.hpp"
#include "infrastructure/utils/TerminalColor.hpp"
#include <iostream>
#include <stdexcept>

StreamWriter::StreamWriter(const StreamWriter&) {}

StreamWriter::~StreamWriter() {}

StreamWriter& StreamWriter::operator=(const StreamWriter&) {
  throw std::runtime_error("Copying of StreamWriter is not allowed");
}

void StreamWriter::print(StrColor strColor, const std::string &str) {
  std::cout << TerminalColor::setColor(strColor, str) << std::endl;
}

void StreamWriter::print(StrColor strColor, BgColor bgColor, const std::string &str) {
  std::cout << TerminalColor::setColor(bgColor, strColor, str) << std::endl;
}
