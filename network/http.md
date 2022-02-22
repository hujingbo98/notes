<!--
 * @Author : Hu Jingbo
 * @Date   : 2021-11-04
-->

# 超文本传送协议 (HTTP)

超文本传送协议 (HTTP, Hypertext Transfer Protocol) 是万维网 (World Wide Web，WWW，也简称为Web) 的基础。

HTTP 是一个简单的协议。客户进程建立一条同服务器进程的 TCP 连接，然后发出请求并读取服务器进程的响应。服务器进程关闭连接表示本次响应结束。服务器进程返回的文件通常含有指向其他服务器上文件的指针（超文本链接）。用户显然可以很轻松地沿着这些链接从一个服务器到下一个服务器。

## 报文格式

HTTP/1.0 报文有两种类型，请求和响应报文。

HTTP/1.0 的请求和响应报文的首部均可包含可变数量的字段。用一个空行将所有首部字段与报文主体分隔开来。一个首部字段由字段名和随后的冒号、一个空格和字段值组成，字段名不区分大小写。

### 请求报文

HTTP/1.0 请求的格式是：

```txt
request-line
headers (0 或有多个)
<blank line>
body (只对 POST 请求有效)
```

request-line 的格式是：`request request-URI HTTP版本号`。以请求类型开始，后面跟着请求资源，最后是 HTTP 版本号。

支持以下 3 个请求：

1. GET 请求，返回 request-URI 所指出的任意信息。

2. HEAD 请求，类似于 GET 请求，但服务器程序只返回指定文档的首部信息，而不包含实际的文档内容。该请求通常被用来测试超文本链接的正确性、可访问性和最近的修改。

3. POST 请求用来发送电子邮件、新闻或发送能由交互用户填写的表格。这是唯一需要在请求中发送 body 的请求。使用 POST 请求时需要在报文首部 Content-Length 字段中指出 body 的长度。

### 响应报文

```txt
status-line
headers (0 个或有多个)
<blank line>
body
```
* status-line

状态行 (status-line) 的格式是：`HTTP版本号 response-code response-phrase`。以 HTTP 版本号开始，后面跟着 3 位数字表示响应代码，最后是易读的响应短语。

下图列出了3位数字的响应代码的含义。根据第 1 位可以把响应分成 5 类。

```txt
          | "100": Continue
          | "101": Switching Protocols
          | "200": OK
          | "201": Created
          | "202": Accepted
          | "203": Non-Authoritative Information
          | "204": No Content
          | "205": Reset Content
          | "206": Partial Content
          | "300": Multiple Choices
          | "301": Moved Permanently
          | "302": Found
          | "303": See Other
          | "304": Not Modified
          | "305": Use Proxy
          | "307": Temporary Redirect
          | "400": Bad Request
          | "401": Unauthorized
          | "402": Payment Required
          | "403": Forbidden
          | "404": Not Found
          | "405": Method Not Allowed
          | "406": Not Acceptable
          | "407": Proxy Authentication Required
          | "408": Request Time-out
          | "409": Conflict
          | "410": Gone
          | "411": Length Required
          | "412": Precondition Failed
          | "413": Request Entity Too Large
          | "414": Request-URI Too Large
          | "415": Unsupported Media Type
          | "416": Requested range not satisfiable
          | "417": Expectation Failed
          | "500": Internal Server Error
          | "501": Not Implemented
          | "502": Bad Gateway
          | "503": Service Unavailable
          | "504": Gateway Time-out
          | "505": HTTP Version not supported
```

## 首部字段
