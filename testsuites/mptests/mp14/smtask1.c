/* SPDX-License-Identifier: BSD-2-Clause */

/*  Sm_test_task
 *
 *  This task continuously obtains and releases a global semaphore.
 *
 *  Input parameters:
 *    argument - task argument
 *
 *  Output parameters:  NONE
 *
 *  COPYRIGHT (c) 1989-1999.
 *  On-Line Applications Research Corporation (OAR).
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "system.h"

rtems_task Semaphore_task(
  rtems_task_argument argument
)
{
  uint32_t    count;
  rtems_status_code status;
  uint32_t    yield_count;

  puts( "Getting SMID of semaphore" );
  while ( FOREVER ) {
    status = rtems_semaphore_ident(
      Semaphore_name[ 1 ],
      RTEMS_SEARCH_ALL_NODES,
      &Semaphore_id[ 1 ]
    );
    if ( status == RTEMS_SUCCESSFUL )
      break;
    puts( "rtems_semaphore_ident FAILED!!" );
    rtems_task_wake_after(2);
  }

  yield_count = 100;

  while ( Stop_Test == false ) {

    for ( count=SEMAPHORE_DOT_COUNT ; Stop_Test == false && count ; count-- ) {
      status = rtems_semaphore_obtain(
        Semaphore_id[ 1 ],
        RTEMS_DEFAULT_OPTIONS,
        RTEMS_NO_TIMEOUT
      );
      directive_failed( status, "rtems_semaphore_obtain" );

      status = rtems_semaphore_release( Semaphore_id[ 1 ] );
      directive_failed( status, "rtems_semaphore_release" );

      if ( Stop_Test == false )
        if ( rtems_object_get_local_node() == 1 && --yield_count == 0 ) {
          status = rtems_task_wake_after( RTEMS_YIELD_PROCESSOR );
          directive_failed( status, "rtems_task_wake_after" );

          yield_count = 100;
        }
    }
    put_dot( 's' );
  }

  Exit_test();
}
