/** \file telem.cpp
  * \brief The MagAO-X logger telemetery library
  * \author Jared R. Males (jaredmales@gmail.com)
  *
  * \ingroup logger_types_files
  *
  */
#include <XWCTK/lib/flatlogs/include/flatlogs/flatlogs.hpp>
#include "../generated/logTypes.hpp"

namespace MagAOX
{
namespace logger
{

timespec telem_fsm::lastRecord = {0,0};

} //namespace logger
} //namespace MagAOX