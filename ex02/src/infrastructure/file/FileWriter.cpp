/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileWriter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 18:03:52 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/26 19:30:05 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infrastructure/file/FileWriter.hpp"
#include <fstream>
#include <stdexcept>

FileWriter::FileWriter(const FileWriter&) {}

FileWriter& FileWriter::operator=(const FileWriter&) {
  throw std::runtime_error("Copying of StreamWriter is not allowed");
}

FileWriter::~FileWriter() {}

void FileWriter::writeToFile(const std::string &filename, const std::string &content) {
  std::ofstream outfile(filename.c_str());
  if (!outfile.is_open()) {
    throw std::runtime_error("Could not open file " + filename);
  }
  outfile << content;
  outfile.close();
}
