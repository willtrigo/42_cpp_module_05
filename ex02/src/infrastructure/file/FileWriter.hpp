/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileWriter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 17:59:52 by dande-je          #+#    #+#             */
/*   Updated: 2025/07/18 17:30:09 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_WRITER_HPP
#define FILE_WRITER_HPP

#include <string>
class FileWriter {
 public:
  static void writeToFile(const std::string& filename, const std::string& content);

 private:
  FileWriter();
  FileWriter(const FileWriter&);
  FileWriter& operator=(const FileWriter&);
  ~FileWriter();
};

#endif // FILE_WRITER_HPP
