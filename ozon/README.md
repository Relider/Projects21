# Тестовое задание для стажера-разработчика

## Описание задачи
Реализовать систему для добавления и чтения постов и комментариев с использованием GraphQL, 
аналогичную комментариям к постам на популярных платформах, таких как Хабр или Reddit. 

### Характеристики системы постов: 
- Можно просмотреть список постов. 
- Можно просмотреть пост и комментарии под ним. 
- Пользователь, написавший пост, может запретить оставление комментариев к своему посту. 

### Характеристики системы комментариев к постам: 
- Комментарии организованы иерархически, позволяя вложенность без ограничений. 
- Длина текста комментария ограничена до, например, 2000 символов. 
- Система пагинации для получения списка комментариев.

## Запуск

# локальный запуск
- make local.run

# Запуск в Docker
- make docker.run 

# Запуск тестов
- make tests.run

# Остановка работы Docker
- make docker.down

## Примеры запросов
### Создание поста
```graphql
mutation CreatePost {
    CreatePost(
        post: {
            name: "Very good day"
            content: "Lets speak about content"
            author: "Author1"
            commentsAllowed: true
        }
    ) {
        id
        createdAt
        name
        author
        content
    }
}

```

### Получение списка постов

```graphql
query GetAllPosts {
    GetAllPosts(page: 1, pageSize: 3) {
        id
        createdAt
        name
        author
        content
    }
}

```

### Получение детальной информации о посте

```graphql
query GetPostById {
    GetPostById(id: 1) {
        id
        createdAt
        name
        author
        content
        commentsAllowed
        comments(page: 1, pageSize: 2) {
            id
            createdAt
            author
            content
            post
            replies {
                id
                createdAt
                author
                content
                post
                replyTo
            }
        }
    }
}

```

### Создание комментария

```graphql
mutation CreateComment {
    CreateComment(input: { author: "Author2", content: "Dont bad", post: "1" }) {
        id
        createdAt
        author
        content
        post
        replyTo
    }
}
```

### Подписка на комментарии поста

```graphql
subscription CommentsSubscription {
    CommentsSubscription(postId: "1") {
        id
        createdAt
        author
        content
        post
        replyTo
    }
}
```