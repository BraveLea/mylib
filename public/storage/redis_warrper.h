#ifndef _MIG_FM_REDIS_WARRPER_H__
#define _MIG_FM_REDIS_WARRPER_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hiredis.h"
#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef struct warrper_redis_context_t {
    redisContext*	context;
}warrper_redis_context_t;

typedef struct warrper_redis_reply_t{
	redisReply* reply;
}warrper_redis_reply_t;



char* RedisConnections(warrper_redis_context_t** context ,
					const char* host,const int port,const char* pwd);

int RedisSelectDB(warrper_redis_context_t** context,
        const char* db_name);

int RedisAddValue(warrper_redis_context_t* context,
				const char* key,const size_t key_len,
				const char* val,const size_t val_len);

int RedisGetValue(warrper_redis_context_t* context,
				const char* key,const size_t key_len,
				char** val,size_t *val_len);

int ReidsIsExist(warrper_redis_context_t* context,
				 const char* key,const size_t key_len);

int RedisDelValue(warrper_redis_context_t* context,
			   const char* key,const size_t key_len);

int RedisIncDecValue(warrper_redis_context_t* context,
		   const char* key, size_t key_len, long long incby, long long *result);
							
int RedisPingRedis(warrper_redis_context_t* context);

int RedisClose(warrper_redis_context_t* context);

int RedisIncr(warrper_redis_context_t* context,
			  const char* key,const size_t key_len);

int RedisDecr(warrper_redis_context_t* context,
			  const char* key,const size_t key_len);

int RedisAddHashElement(warrper_redis_context_t* context,const char* hash_name,
						const char* key,const size_t key_len,
						const char* val,const size_t val_len);

int RedisSetHashElement(warrper_redis_context_t* context,const char* hash_name,
						const char* key,const size_t key_len,
						const char* val,const size_t val_len);

int RedisGetHashElement(warrper_redis_context_t* context,const char* hash_name,
						const char* key,const size_t key_len,
						char** val,size_t* val_len);

int RedisDelHashElement(warrper_redis_context_t* context,const char* hash_name,
						const char* key,const size_t key_len);

long long RedishHashSize(warrper_redis_context_t* context,const char* hash_name);

int RedisDelHash(warrper_redis_context_t* context,const char* hash_name);

int RedisAddListElement(warrper_redis_context_t* context,
				const char* key,const size_t key_len,
				const char* val,const size_t val_len,
				const int flag);
				

int RedisGetListElement(warrper_redis_context_t* context,
				const char* key,const size_t key_len,int index,
				char** val,size_t *val_len);
			
int RedisDelListElement(warrper_redis_context_t* context,int index,
			   const char* key,const size_t key_len);

int RedisPopListElement(warrper_redis_context_t* context,
		   const char* key,const size_t key_len,char** val,size_t *val_len,
		   const int flag);
			  
int RedisSetListElement(warrper_redis_context_t* context,int index,
					const char* key,const size_t key_len,
					const char* val,const size_t val_len);

long long ReidsGetListSize(warrper_redis_context_t* context,const char* key,
					  const size_t key_len);

warrper_redis_reply_t* RedisGetListAll(warrper_redis_context_t* context,
									   const char* key,const size_t key_len,
									   char***val,int* val_len);

warrper_redis_reply_t* RedisGetHashValueAll(warrper_redis_context_t* context,
											const char* key,const size_t key_len,
											char***val,int* val_len);
// add by tianyiheng at 2016/03/04
warrper_redis_reply_t* RedisGetHashKeysAll(warrper_redis_context_t* context,
                      const char* key,const size_t key_len,
                      char***val,int* val_len);

warrper_redis_reply_t* RedisGetAllHash(warrper_redis_context_t* context,
									   const char* key,const size_t key_len,
									   char***val,int* val_len);

//  add by jiaoyognqing at 2016/7/ 15:00:00
//  head 和 tail 定位set中的一个范围。order指出顺序, order=0:从小到大, order = 1:从大到小
warrper_redis_reply_t* RedisGetSortedSet(warrper_redis_context_t* context, \
                                                          const char* key, \
                                                          const size_t key_len, \
                                                          char***val, \
                                                          int* val_len, \
                                                          const char* head, \
                                                          const char* tail, \
                                                          int order);

int RedisFreeReply(warrper_redis_reply_t* wa);

warrper_redis_reply_t *RedisGetListRange(warrper_redis_context_t* context,const char* key,const size_t key_len,
		int from, int to, char***val, int* val_len);

warrper_redis_reply_t *RedisDoCommand(warrper_redis_context_t* context, const char *format/*, ...*/);
warrper_redis_reply_t *RedisDoCommandV(warrper_redis_context_t* context, const char *format, va_list ap);

// add by tianyiheng at 2016/03/04 11:00:00
// pipelining command for redis
int RedisAppendCommand(warrper_redis_context_t * contex_warrper, const char *command);
int RedisAppendCommandV(warrper_redis_context_t *contex_warrper, const char *format, ...);
int RedisGetReply(warrper_redis_context_t *contex_warrper, void **reply);
int RedisAppendCmdV(warrper_redis_context_t *context_warrper, const char *format, va_list ap);

#ifdef __cplusplus
}
#endif
#endif

